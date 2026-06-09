### 解题思路
2ms，java，击败100%

方法：
1、排除无法爬的山（长度3之内）
2、从0-length，找尖峰，
找到尖峰就统计两侧长度

### 代码

```java
class Solution {
    public int longestMountain(int[] A) {
        //排除不具备爬山资格的数组，长度0、1、2
        if(A.length<3){
            return 0;
        }
        int longest = 0;
        for(int i=1;i<A.length-1;i++){
            //找尖峰
            if(A[i-1] < A[i] && A[i] > A[i+1]){
                int length = 1;
                //统计左边
                for(int j=i-1;j>=0;j--){
                    if(A[j] < A[j+1]){
                        length++;
                        //System.out.println("上坡");
                    }else {
                        break;
                    }
                }
                //统计右边
                for (int j = i+1; j < A.length; j++) {
                    if(A[j-1] > A[j]){
                        length++;
                        //System.out.println("下坡");
                    }else{
                        break;
                    }
                }
                //记录最大值
                longest = longest>length?longest:length;
            }
        }
        return longest;
    }
}
```