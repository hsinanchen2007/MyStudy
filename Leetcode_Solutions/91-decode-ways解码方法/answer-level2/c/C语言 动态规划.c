![image.png](https://pic.leetcode-cn.com/1dfb713ff4543ee07cd9669d25fc8b8a75935b5566568fd07f8944193df3fbb3-image.png)
```
/*
解题思想：动态规划。
解题步骤：
	1、确定状态：
		字符串s = “226”
		字符串长度记为：len
		长度为len的纯数字字符串中解码总数记为：F[len]
	2、转移方程：
		F[len] = (F[len-1]) + (F[len-2])，从长度为0、1、2、3的字符串总结出来的。
		详见上图
	3、初始条件和边界情况：以下的边界情况是可以浓缩的，懒得弄了。
		a、len = 0：
			F[0] = 0;
		b、len = 1：
			if(s[len-1] == 0){
				F[1] = 0;
			}
			else{
				F[1] = 1;
			}
		c、len = 2:
			if(s[len-2] == 0){
				F[2] = 0;
			}else{
				if(s[len-2] == 1){
					if(s[len-1] == 0){
						F[len] = 1;
					}else{
						F[len] = 2;
					}
				}else if(s[len-2] == 2){
					if(s[len-1] == 0 || (s[len-1] >= 7 && s[len-1] <= 9)){
						F[len] = 1;
					}else{
						F[len] = 2;
					}
				}else{
					if(s[len-1] == 0){
						F[len] = 0;
					}else{
						F[len] = 1;
					}
				}
			}
			
		d、len>=3:
			if(s[i]) == 0){
				if(s[i-1]==0){
					return 0;
				}else if(s[i-1]==1 || s[i-1] == 2){
					F(i)= F(i-2);
				}else{
					F[i] = 0;
				}
			}else{
				if(s[i-1] = 0){
					F(i) = F[i-1];
				}else if(s[i-1] = 1){
					F(i) = F[i-1] + F[i-2];
				}else if(s[i-1] = 2){
					if(s[i]>=7 && s[i]<=9){
						F(i) = F[i-1];
					}else if(s[i]>=1 && s[i]<=6){
						F(i) = F[i-1] + F[i-2];
					}
				}else if(s[i-1] >= 3 && s[i-1] <= 9){
					F(i) = F[i-1];	
				}else{
					
				}
			}
	4、计算顺序：从前向后按照子字符串长度进行计算。
		a、第一层循环：字符串长度为变量，len∈[1,len]，对应的
		
	5、整个计算过程中，只要存储dp[i-2]、dp[i-1]、dp[i]几个
		
	注意：
		1、时间复杂度：O(n)，遍历一次即可
		2、空间复杂度：O(1),因为只定义了常数个整形变量。

代码可以再精简，也是懒得搞了。
*/
int numDecodings(char * s){
    int i;
    int dp0;//dp[i-2]
    int dp1;//dp[i-1];
    int dp;//dp[i];
    int len = 0;
    
    len = strlen(s);
    if(len == 0){
        return 0;
    }
    
    if(s[0] == '0'){
        return 0;
    }
    
    if(len == 1){
        if(s[0] == '0'){
            return 0;
        }else{
            return 1;
        }
    }else if(len == 2){
        if(s[len - 2] == '0'){
            return 0;
        }else if(s[len - 2] == '1'){
            if(s[len -1] == '0'){
                return 1;
            }else{
                return 2;
            } 
        }else if(s[len - 2] == '2'){
            if(s[len-1] == '0' || (s[len-1] >= '7' && s[len-1] <= '9')){
                return 1;
            }else{
                return 2;
            }
        }else{
            if(s[len-1] == '0'){
                return 0;
			}else{
                return 1;
            }
        }
        
    }else{//len >= 3的情况
        if(s[0] == '0'){
            return 0;
        }else if(s[0] == '1'){
            if(s[1] == '0'){
                dp0 = 1;
                dp1 = 1;
            }else{
                dp0 = 1;
                dp1 = 2;
            } 
        }else if(s[0] == '2'){
            if(s[1] == '0' || (s[1] >= '7' && s[1] <= '9')){
                dp0 = 1;
                dp1 = 1;
            }else{
                dp0 = 1;
                dp1 = 2;
            }
        }else{
            if(s[1] == '0'){
                dp0 = 1;
                dp1 = 0;
			}else{
                dp0 = 1;
                dp1 = 1;
            }
        }
        
        for(i = 2;i < len;i++){//从第3个字符开始计算
            if(s[i] == '0'){
				if(s[i-1] == '0'){
					return 0;
				}else if(s[i-1]=='1' || s[i-1] == '2'){
					dp = dp0;
				}else{
					dp = 0;
				}
			}else{
				if(s[i-1] == '0'){
					dp = dp1;
				}else if(s[i-1] == '1'){
					dp = dp1 + dp0;
				}else if(s[i-1] == '2'){
					if(s[i] >= '7' && s[i] <= '9'){
						dp = dp1;
					}else if(s[i] >= '1' && s[i] <= '6'){
						dp = dp1 + dp0;
					}
				}else if(s[i-1] >= '3' && s[i-1] <= '9'){
					dp = dp1;	
				}else{
                    printf("you have some unconsidered case!!!\n");
				}
			}
            dp0 = dp1;
            dp1 = dp;
        }
    }
    return dp1;  
}

```
