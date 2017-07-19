/******************** LQ_K60_函数库 v1.0 ********************
 * 文件名           ：FTM.c
 * 功能             ：设置FTM工作模式
 * 备注             ：官方例程上修改
 * 日期             ：2016-09-01
 * 实验平台         ：龙丘 K60VG核心板 
 * 开发环境         ：IAR 7.3
 * 作者             ：龙丘技术 006
 * 淘宝店           ：https://longqiu.taobao.com
 * 龙丘智能车讨论群 ：202949437
*************************************************************/

#include "include.h"
#include "FTM.h"

FTM_MemMapPtr FTMN[3] = {FTM0_BASE_PTR, FTM1_BASE_PTR, FTM2_BASE_PTR}; //定义三个指针数组保存 FTMn_e 的地址

//-------------------------------------------------------------------------*
//函数名: FTM_PWM_init                                                        
//功  能: FTM的PWM功能                                                        
//参  数: ftmn:模块名FTM0,FTM1，FTM2
//        ch  :通道号 对应引脚参考ftm.h文件
//        mod :脉冲宽度  范围（0~65535）
//        cv  :高电平宽度 范围（0~mod）
//返  回: 无                                                              
//简  例: FTM_PWM_Init(FTM0,FTM_CH6,65535,32768); 这样占空比是50%                                 
//-------------------------------------------------------------------------*
void FTM_PWM_Init(FTMn_e ftmn, FTM_CHn_e ch, u16 mod, u16 cv)
{
  
  /******************* 开启时钟 和 复用IO口*******************/
    switch(ftmn)
    {
    case FTM0:
        SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;       //使能FTM0时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM0_CH0 == PTC1)
            {
              
                PORTC_PCR1= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH0 == PTA3)
            {
              
                PORTA_PCR3= PORT_PCR_MUX(3); 
            }
            else
            {
                 break;
            }
            break;

        case FTM_CH1:
            if(FTM0_CH1 == PTC2)
            {
               
                PORTC_PCR2= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH1 == PTA4)
            {
              
                PORTA_PCR4= PORT_PCR_MUX(3); 
            }
            else
            {
                 break;
            }
            break;

        case FTM_CH2:
            if(FTM0_CH2 == PTC3)
            {
              
                PORTC_PCR3= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH2 == PTA5)
            {
              
                PORTA_PCR5= PORT_PCR_MUX(3); 
            }
            else
            {
                 break;
            }
            break;

        case FTM_CH3:
            if(FTM0_CH3 == PTC4)
            {
             
                PORTC_PCR4= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH3 == PTA6)
            {
              
                PORTA_PCR6= PORT_PCR_MUX(3); 
            }
            else
            {
                break;
            }
            break;

        case FTM_CH4:
            if(FTM0_CH4 == PTD4)
            {
              
                PORTD_PCR4= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH4 == PTA7)
            {
             
                PORTA_PCR7= PORT_PCR_MUX(3); 
            }
            else
            {
               break;
            }
            break;

        case FTM_CH5:
            if(FTM0_CH5 == PTD5)
            {
             
                PORTD_PCR5= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH5 == PTA0)
            {
              
                PORTA_PCR0= PORT_PCR_MUX(3); 
            }
            else
            {
                 break;
            }
            break;

        case FTM_CH6:
            if(FTM0_CH6 == PTD6)
            {
             
                PORTD_PCR6= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH6 == PTA1)
            {
             
                PORTA_PCR1= PORT_PCR_MUX(3); 
            }
            else
            {
                break;
            }
            break;

        case FTM_CH7:
            if(FTM0_CH7 == PTD7)
            {
              
                PORTD_PCR7= PORT_PCR_MUX(4); 
            }
            else if(FTM0_CH7 == PTA2)
            {
             
                PORTA_PCR2= PORT_PCR_MUX(3); 
            }
            else
            {
               break;
            }
            break;
        default:
            return;
        }
        break;

    case FTM1:
        SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;       //使能FTM1时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM1_CH0 == PTA8)
            {
               
                PORTA_PCR8= PORT_PCR_MUX(3); 
            }
            else if(FTM1_CH0 == PTA12)
            {
                PORTA_PCR12= PORT_PCR_MUX(3); 
            }
            else if(FTM1_CH0 == PTB0)
            {
                PORTB_PCR0= PORT_PCR_MUX(3); 
            }
            break;


        case FTM_CH1:
            if(FTM1_CH1 == PTA9) 
            {
               
                PORTA_PCR9= PORT_PCR_MUX(3); 
            }
            else if(FTM1_CH1 == PTA13)
            {
                PORTA_PCR13= PORT_PCR_MUX(3); 
            }
              else if(FTM1_CH1 == PTB1)
            {
                PORTB_PCR1= PORT_PCR_MUX(3); 
            }
            break;

        default:
            return;
        }
        break;

    case FTM2:
        SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK;                           //使能FTM2时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM2_CH0 == PTA10)
            {
              
                PORTA_PCR10= PORT_PCR_MUX(3); 
            }
            else if(FTM2_CH0 == PTB18)
            {
                PORTB_PCR18= PORT_PCR_MUX(3); 
            }
            break;

        case FTM_CH1:
            if(FTM2_CH1 == PTA11) 
            {
             
                PORTA_PCR11= PORT_PCR_MUX(3); 
            }
            else if(FTM2_CH1 == PTB19)
            {
                PORTB_PCR19= PORT_PCR_MUX(3); 
            }
            break;

        default:
            return;
        }
        break;
    default:
        break;
    }


    /******************** 选择输出模式为 边沿对齐PWM *******************/
    //通道状态控制，根据模式来选择 边沿或电平
    FTM_CnSC_REG(FTMN[ftmn], ch) &= ~FTM_CnSC_ELSA_MASK;
    FTM_CnSC_REG(FTMN[ftmn], ch)  = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;

    /******************** 配置时钟和分频 ********************/
    FTM_SC_REG(FTMN[ftmn])    = ( 0
                                 
                                  | FTM_SC_PS(4)             //分频2^FTM_SC_PS,频率为 100M/16=6.25M
                                  | FTM_SC_CLKS(1)            //时钟选择，bus时钟
                                 
                                );
   // FTM_MODE_REG(FTMN[ftmn])&=~1;
    FTM_MOD_REG(FTMN[ftmn])   = mod;                        //模数, EPWM的周期为 ：MOD - CNTIN + 0x0001
    FTM_CNTIN_REG(FTMN[ftmn]) = 0;                          //计数器初始化值。设置脉冲宽度：(CnV - CNTIN).
    FTM_CnV_REG(FTMN[ftmn], ch) = cv;
    FTM_CNT_REG(FTMN[ftmn])   = 0;                          //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）
}



//-------------------------------------------------------------------------*
//函数名: FTM_PWM_Duty                                                        
//功  能: 改变PWM的占空比                                                        
//参  数: ftmn:模块名FTM0,FTM1，FTM2
//        ch  :通道号 对应引脚参考ftm.h文件
//        duty:高电平宽度  范围（0~mod）mod在初始化的时候设定
//返  回: 无                                                              
//简  例: FTM_PWM_Duty(FTM0, FTM_CH6,duty);duty设定在0~mod之间的任何数                                
//-------------------------------------------------------------------------*
void FTM_PWM_Duty(FTMn_e ftmn, FTM_CHn_e ch, u16 duty)
{
 
    FTM_CnV_REG(FTMN[ftmn], ch) = duty;

}


//////////////////////////////// 以下为正交解码 //////////////////////////////////////////



//-------------------------------------------------------------------------*
//函数名: FTM_AB_Init                                                        
//功  能: 初始化FTM的正交解码功能                                                      
//参  数: ftmn:模块名FTM1，FTM2
//返  回: 无                                                              
//简  例:  FTM_AB_Init(FTM2);                               
//-------------------------------------------------------------------------*
void FTM_AB_Init(FTMn_e ftmn)
{
   

    /******************* 开启时钟 和 复用IO口*******************/
    switch(ftmn)
    {

    case FTM1:
        SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;       //使能FTM1时钟
        if(FTM1_QDPHA == PTA8)                  //管脚复用
        {
          
             PORTA_PCR8= PORT_PCR_MUX(6);
        }
        else if(FTM1_QDPHA == PTA12)
        {
           
             PORTA_PCR12= PORT_PCR_MUX(7);
        }
        else if(FTM1_QDPHA == PTB0)
        {
         
             PORTB_PCR0= PORT_PCR_MUX(6);
        }
        else
        {
             break;
        }

        if(FTM1_QDPHB == PTA9)
        {
         
             PORTA_PCR9= PORT_PCR_MUX(6);
        }
        else if(FTM1_QDPHB == PTA13)
        {
        
             PORTA_PCR13= PORT_PCR_MUX(7);
        }
        else if(FTM1_QDPHB == PTB1)
        {
         
             PORTB_PCR1= PORT_PCR_MUX(6);
        }
        else
        {
            break;
        }
        break;
       

    case FTM2:
        SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK;                           //使能FTM2时钟
        if(FTM2_QDPHA == PTA10)                  //管脚复用
        {
        
             PORTA_PCR10= PORT_PCR_MUX(6);
        }
        else if(FTM2_QDPHA == PTB18)
        {
         
             PORTB_PCR18= PORT_PCR_MUX(6);
        }
        else
        {
            break;
        }

        if(FTM2_QDPHB == PTA11)                  //管脚复用
        {
          
             PORTA_PCR11= PORT_PCR_MUX(6);
        }
        else if(FTM2_QDPHB == PTB19)
        {
        
             PORTB_PCR19= PORT_PCR_MUX(6);
        }
        else
        {
             break;    
        }break;
    }

    FTM_MODE_REG(FTMN[ftmn])  |=    (0
                                     | FTM_MODE_WPDIS_MASK  //写保护禁止
                                     //| FTM_MODE_FTMEN_MASK   //使能 FTM
                                    );
    FTM_QDCTRL_REG(FTMN[ftmn]) |=   (0
                                    | FTM_QDCTRL_QUADMODE_MASK
                                     );
    FTM_CNTIN_REG(FTMN[ftmn])   = 0;
    FTM_MOD_REG(FTMN[ftmn])     = FTM_MOD_MOD_MASK;
    FTM_QDCTRL_REG(FTMN[ftmn]) |=   (0
                                    | FTM_QDCTRL_QUADEN_MASK
                                     );
    FTM_MODE_REG(FTMN[ftmn])  |= FTM_QDCTRL_QUADEN_MASK;;
    FTM_CNT_REG(FTMN[ftmn])     = 0;                    //计数器。只有低16位可用（写任何值到此寄存器，都会加载 CNTIN 的值）
    
}


//-------------------------------------------------------------------------*
//函数名: FTM_AB_get                                                        
//功  能: 获取FTM正交解码的脉冲数                                                      
//参  数: ftmn:模块名FTM1，FTM2
//返  回: val                                                             
//简  例: speed=FTM_AB_get(FTM2);                              
//-------------------------------------------------------------------------*
int16 FTM_AB_Get(FTMn_e ftmn)
{
    int16 val;
   
    val = FTM_CNT_REG(FTMN[ftmn]);
    
    FTM_CNT_REG(FTMN[ftmn]) = 0;             

    return val;
}



//-------------------------------------------------------------------------*
//函数名: FTM_Input_init                                                        
//功  能: FTM的输入捕捉功能                                                        
//参  数: ftmn:模块名FTM0,FTM1，FTM2
//        ch  :通道号 对应引脚参考ftm.h文件
//        cfg :触发方式  :
//                        FTM_Rising,               //上升沿捕捉
//                        FTM_Falling,              //下降沿捕捉
//                        FTM_Rising_or_Falling     //跳变沿捕捉
//返  回: 无                                                              
//简  例: FTM_Input_init(FTM0,FTM_CH6,FTM_Rising);                                
//-------------------------------------------------------------------------*
void FTM_Input_init(FTMn_e ftmn, FTM_CHn_e ch, FTM_Input_cfg cfg)
{
   
    /******************* 开启时钟 和 复用IO口*******************/
    switch(ftmn)
    {
    case FTM0:
        SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;       //使能FTM0时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM0_CH0 == PTC1)
            {
                PORTC_PCR1= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH0 == PTA3)
            {
                PORTA_PCR3= PORT_PCR_MUX(3);
            }
            else
            {
               ;                      
            }
            break;

        case FTM_CH1:
            if(FTM0_CH1 == PTC2)
            {
                PORTC_PCR2= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH1 == PTA4)
            {
                PORTA_PCR4= PORT_PCR_MUX(3);
            }
            else
            {
                ;                      //设置管脚有误？
            }
            break;

        case FTM_CH2:
            if(FTM0_CH2 == PTC3)
            {
                PORTC_PCR3= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH2 == PTA5)
            {
                PORTA_PCR5= PORT_PCR_MUX(3);
            }
            else
            {
                ;                      //设置管脚有误？
            }
            break;

        case FTM_CH3:
            if(FTM0_CH3 == PTC4)
            {
                PORTC_PCR4= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH3 == PTA6)
            {
                PORTA_PCR6= PORT_PCR_MUX(3);
            }
            else
            {
                ;                      //设置管脚有误？
            }
            break;

        case FTM_CH4:
            if(FTM0_CH4 == PTD4)
            {
                PORTD_PCR4= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH4 == PTA7)
            {
                PORTA_PCR7= PORT_PCR_MUX(3);
            }
            else
            {
               ;                      //设置管脚有误？
            }
            break;

        case FTM_CH5:
            if(FTM0_CH5 == PTD5)
            {
                PORTD_PCR5= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH5 == PTA0)
            {
                PORTA_PCR0= PORT_PCR_MUX(3);
            }
            else
            {
                ;                      //设置管脚有误？
            }
            break;

        case FTM_CH6:
            if(FTM0_CH6 == PTD6)
            {
                PORTD_PCR6= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH6 == PTA1)
            {
                PORTA_PCR1= PORT_PCR_MUX(3);
            }
            else
            {
               ;                      //设置管脚有误？
            }
            break;

        case FTM_CH7:
            if(FTM0_CH7 == PTD7)
            {
                PORTD_PCR7= PORT_PCR_MUX(4);
            }
            else if(FTM0_CH7 == PTA2)
            {
                PORTA_PCR2= PORT_PCR_MUX(3);
            }
            else
            {
               ;                      //设置管脚有误？
            }
            break;
        default:
            return;
        }
        break;

    case FTM1:
        SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;       //使能FTM1时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM1_CH0 == PTA8)
            {
                PORTA_PCR8= PORT_PCR_MUX(3);
            }
            else if(FTM1_CH0 == PTA12) 
            {
               PORTA_PCR12= PORT_PCR_MUX(3);
            }
            else if(FTM1_CH0 == PTB0)
            {
               PORTB_PCR0= PORT_PCR_MUX(3);
            }
            break;


        case FTM_CH1:
            if(FTM1_CH1 == PTA9 )
            {
                PORTA_PCR9= PORT_PCR_MUX(3);
            }
            else if  (FTM1_CH1 == PTA13) 
            {
                PORTA_PCR13= PORT_PCR_MUX(3);
            }
            else if(FTM1_CH1 == PTB1)
            {           
                PORTB_PCR1= PORT_PCR_MUX(3);
            }
            break;

        default:
            return;
        }
        break;

    case FTM2:
        SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK;                           //使能FTM2时钟
        switch(ch)
        {
        case FTM_CH0:
            if(FTM2_CH0 == PTA10)
            {   
                PORTA_PCR10= PORT_PCR_MUX(3);
            }
            else if (FTM2_CH0 == PTB18) 
            {
               PORTB_PCR18= PORT_PCR_MUX(3);        
            }
            break;

        case FTM_CH1:
            if(FTM2_CH1 == PTA11)
            {
                PORTA_PCR11= PORT_PCR_MUX(3);
            }
            else if(FTM2_CH1 == PTB19)
            {
               PORTB_PCR19= PORT_PCR_MUX(3);                    
            }
            break;

        default:
            return;
        }
        break;
    default:
        break;
    }

    /******************* 设置为输入捕捉功能 *******************/
    switch(cfg)
    {
        //输入捕捉模式下：DECAPEN = 0 ， DECAPEN = 0 ，CPWMS = 0， MSnB:MSnA = 0

        // ELSnB:ELSnA         1          10          11
        // 配置             上升沿      下降沿      跳变沿

    case FTM_Rising:    //上升沿触发
        FTM_CnSC_REG(FTMN[ftmn], ch) |=  ( FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK );                   //置1
        FTM_CnSC_REG(FTMN[ftmn], ch) &= ~( FTM_CnSC_ELSB_MASK  | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //清0
        break;

    case FTM_Falling:   //下降沿触发
        FTM_CnSC_REG(FTMN[ftmn], ch) |= (FTM_CnSC_ELSB_MASK  | FTM_CnSC_CHIE_MASK );                    //置1
        FTM_CnSC_REG(FTMN[ftmn], ch) &= ~( FTM_CnSC_ELSA_MASK | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK); //清0
        break;

    case FTM_Rising_or_Falling: //上升沿、下降沿都触发
        FTM_CnSC_REG(FTMN[ftmn], ch) |=  ( FTM_CnSC_ELSB_MASK | FTM_CnSC_ELSA_MASK  | FTM_CnSC_CHIE_MASK ); //置1
        FTM_CnSC_REG(FTMN[ftmn], ch) &= ~( FTM_CnSC_MSB_MASK  | FTM_CnSC_MSA_MASK); //清0
        break;
    }

    FTM_SC_REG(FTMN[ftmn]) = FTM_SC_CLKS(0x1);       //选择 bus 时钟

    FTM_MODE_REG(FTMN[ftmn])    |= FTM_MODE_WPDIS_MASK; //禁止写保护
    FTM_COMBINE_REG(FTMN[ftmn]) = 0;
    FTM_MODE_REG(FTMN[ftmn])    &= ~FTM_MODE_FTMEN_MASK;    //使能FTM
    FTM_CNTIN_REG(FTMN[ftmn])   = 0;

    FTM_STATUS_REG(FTMN[ftmn])  = 0x00;               //清中断标志位

    //开启输入捕捉中断
    //enable_irq(62 + ftmn);
}


//-------------------------------------------------------------------------*
//函数名: FTM_interrupt                                                        
//功  能: FTM的中断功能                                                        
//返  回: 无                                                              
//简  例: 无                               
//-------------------------------------------------------------------------*
void FTM0_interrupt(void)
{
    uint8 s = FTM0_STATUS;             //读取捕捉和比较状态 
    uint8 CHn;

    FTM0_STATUS = 0x00;             //清中断标志位

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM0, CHn);     //禁止输入捕捉中断
        /*     用户任务       */
        

        /*********************/
        //FTM_IRQ_EN(FTM0, CHn); //开启输入捕捉中断

    }

    /* 这里添加 n=1 的模版，根据模版来添加 */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM0, CHn); //开启输入捕捉中断
        /*     用户任务       */


        /*********************/
        //不建议在这里开启输入捕捉中断
        //FTM_IRQ_EN(FTM0, CHn); //开启输入捕捉中断
    }
}

void FTM1_interrupt(void)//设置波形采集中断
{
    uint8 s = FTM1_STATUS;             //读取捕捉和比较状态 
    uint8 CHn;

    FTM1_STATUS = 0x00;             //清中断标志位

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM1, CHn);     //禁止输入捕捉中断
        /*********************/
       // FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断


    }

    /* 这里添加 n=1 的模版，根据模版来添加 */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断
        /*     用户任务       */


        /*********************/
        //不建议在这里开启输入捕捉中断
        //FTM_IRQ_EN(FTM1, CHn); //开启输入捕捉中断
    }
}


void FTM2_interrupt(void)
{
    uint8 s = FTM2_STATUS;             //读取捕捉和比较状态 
    uint8 CHn;

    FTM2_STATUS = 0x00;             //清中断标志位

    CHn = 0;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_DIS(FTM2, CHn);     //禁止输入捕捉中断
        /*     用户任务       */

        /*********************/
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断

    }

    /* 这里添加 n=1 的模版，根据模版来添加 */
    CHn = 1;
    if( s & (1 << CHn) )
    {
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断
        /*     用户任务       */


        /*********************/
        //不建议在这里开启输入捕捉中断
        //FTM_IRQ_EN(FTM2, CHn); //开启输入捕捉中断
    }
}


/*按键0用来设置灯泡的档位*/
 


