注意的点：
应该是斜边先行！
```
class Solution {
public:
    int countSubstrings(string s) {
       if(s.size()<2) return s.size();
       int n = s.size();
       bool dp[n][n] = {false};
        
       for(int i=0;i<n;i++){
           for(int j=0;j<n-i;j++){
               switch(i){
                   case 0:
                      dp[j][j+i] = true;
                      break;
                   case 1:
                      if(s[j] == s[j+i]){
                          dp[j][j+i] = true;
                      }else{
                          dp[j][j+i] = false;
                      }
                      break;
                   default:
                      dp[j][j+i] = (dp[j+1][j+i-1] and s[j] == s[j+i]);
                      break;
               }
           }
       }
       
       int count =0;
       for(int i=0;i<n;i++){
           for(int j=i;j<n;j++){
               if(dp[i][j]) count ++;
           }
       }
       return count;
    }
};
```


彩蛋： 关于马拉车算法的学习

学习来自https://www.cnblogs.com/grandyang/p/4475985.html 

简短总结：
1. 字符串间隔+ ‘#’ 确保字符串s的长度必为偶数
2. p[i] = 以s[i]为中心的半径长度（从中心到边缘 比如 #2#2# 最中间的# 半径为3）
3. 核心公式  p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;  
其中，id是可以半径扩展到最右端的那个中心,mx是以id为中心的右边最远处位置 例：#2#2# id=2时，mx=5=id+最远半径
![image.png](https://pic.leetcode-cn.com/c87b81d221068bf358ac4e60a2771b9fad3ee3d53f5df107d300281d82442df3-image.png)

![image.png](https://pic.leetcode-cn.com/30c32850938b040e4362cf60e277f81419d5cee3e7ca7bd2ca341e88b384a051-image.png) 

核心公式 基于**看一步走一步**的思想 
p[i]的右半径是否可以再扩大，会根据while循环进行走下去看的
