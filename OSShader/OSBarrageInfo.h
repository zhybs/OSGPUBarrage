//
//  OSBarrageInfo.h
//  OSBufferText
//
//  Created by xu jie on 16/9/22.
//  Copyright © 2016年 xujie. All rights reserved.
//
//--------------------------------------------------
// 每个弹幕包含的信息
// 用户id
// 发送时间
// 等级
// 要显示的信息
// 类型 (文字弹幕或者图片)
//--------------------------------------------------
#import <Foundation/Foundation.h>
#import "OSBarrage.h"
#import "OSTextBarrage.h"

@protocol OSGPUDraw<NSObject>
/*
 * 将顶点数据和纹理数据加载到GPU 中去
 */
-(void)loadVertexAndTextureToGPU;

/*
 * 释放掉顶点数据和加载到GPU中的纹理数据
 */
-(void)deleteVertexAndTextureFromGPU;

/*
 * 绘制到GPU 上去
 */
-(void)drawToGPU;
@end


// 弹幕类型
typedef enum : NSUInteger {
    OSText,
    OSImage,
    
} OSBarrageType;

// 会员等级
typedef enum : NSUInteger {
    OSNormal,
    OSVIP,

} OSRank;

@interface OSBarrageInfo : NSObject<OSGPUDraw>
@property(nonatomic,strong)NSString *uid;
@property(nonatomic,assign)OSRank userRank;
@property(nonatomic,assign)NSTimeInterval timeStamp;
@property(nonatomic,assign,readonly)OSBarrageType type;
@property(nonatomic,strong)OSBarrage *barrage;
@property(nonatomic,assign)NSInteger rate;        // 弹幕速度 1-5 默认为1 




/* 
 * @func  类方法创建对象
 * @param uid 用户的id
 * @param rank 用户等级
 * @param timeStamp 时间戳
 * @param type 弹幕类型
 * @return 对象
 */

+ (OSBarrageInfo*)barrageInfoWithUserID:(NSString*)uid
                               userRank:(OSRank)rank
                              timeStamp:(NSTimeInterval)timeStamp
                            barrageType:(OSBarrageType)type
                                barrage:(OSBarrage*)barrage;

+ (OSBarrageInfo*)barrageInfoWithString:(NSString*)string
                                   font:(UIFont *)font
                                  color:(UIColor *)textColor;




@end
