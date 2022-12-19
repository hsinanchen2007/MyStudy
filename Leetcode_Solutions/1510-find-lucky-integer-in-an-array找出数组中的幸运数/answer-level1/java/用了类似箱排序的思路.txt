### 解题思路

如题QAQ
### 代码

```java
class Solution {
    public int findLucky(int[] arr) {
        
        int[] pinlv=new int[500];
        int maxlucky=-1;
        //初始化
        for(int i=0;i<500;i++){
            pinlv[i]=0;
        }
        //统计
        for(int i=0;i<arr.length;i++){
            pinlv[arr[i]]++;     
        }
        //查找
        for(int i=1;i<500;i++){//不考虑0的情况,0无论是否出现都不能成为幸运数
            if(pinlv[i]==i)
                if(i>maxlucky)
                    maxlucky=i;
        }
        //返回
        return maxlucky;
    }
}
```