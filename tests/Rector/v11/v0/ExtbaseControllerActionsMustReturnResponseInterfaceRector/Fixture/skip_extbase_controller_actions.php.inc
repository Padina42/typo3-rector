<?php

namespace Ssch\TYPO3Rector\Tests\Rector\v11\v0\ExtbaseControllerActionsMustReturnResponseInterfaceRector\Fixture;

use Psr\Http\Message\ResponseInterface;
use TYPO3\CMS\Core\Http\PropagateResponseException;
use TYPO3\CMS\Extbase\Http\ForwardResponse;
use TYPO3\CMS\Extbase\Mvc\Controller\ActionController;

class MyRefactoredController extends ActionController
{
    public function someAction(): ResponseInterface
    {
        $response = $this->responseFactory->createResponse(200);
        throw new PropagateResponseException($response, 200);
    }

    public function someOtherAction(): ResponseInterface
    {
        return new ForwardResponse('another');
    }

    public function somethingAction($range): ResponseInterface
    {
        $years = array_map(static function ($item): string {
            return 'C'.$item.'-';
        }, $range);

        return $this->htmlResponse($years);
    }

    abstract public function listAction($filter = null, string $letter = ''): ResponseInterface;
}

?>

