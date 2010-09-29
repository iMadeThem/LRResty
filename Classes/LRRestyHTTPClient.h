//
//  LRRestyHTTPClient.h
//  LRResty
//
//  Created by Luke Redpath on 29/09/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LRRestyClientResponseDelegate.h"
#import "LRRestyRequest.h"

@class LRRestyRequest;

@protocol LRRestyHTTPClient <NSObject>
- (LRRestyRequest *)getURL:(NSURL *)url parameters:(NSDictionary *)parameters headers:(NSDictionary *)headers delegate:(id<LRRestyRequestDelegate>)requestDelegate;
- (void)postURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers delegate:(id<LRRestyRequestDelegate>)requestDelegate;
- (void)putURL:(NSURL *)url payload:(id)payload headers:(NSDictionary *)headers delegate:(id<LRRestyRequestDelegate>)requestDelegate;
@end

@protocol LRRestyHTTPClientDelegate <NSObject>
@optional
- (void)HTTPClient:(id<LRRestyHTTPClient>)client willPerformRequest:(LRRestyRequest *)request;
@end

@interface LRRestyHTTPClient : NSObject <LRRestyHTTPClient> 
{
  id<LRRestyHTTPClientDelegate> delegate;
  NSOperationQueue *operationQueue;
}
- (id)initWithDelegate:(id<LRRestyHTTPClientDelegate>)aDelegate;
@end