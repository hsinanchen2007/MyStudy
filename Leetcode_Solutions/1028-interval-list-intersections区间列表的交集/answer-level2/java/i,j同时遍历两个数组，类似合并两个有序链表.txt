### 解题思路
![WechatIMG3.jpeg](https://pic.leetcode-cn.com/4309b3c295d4cf2ac2fcdfecf353ec853ac435ef5a7551a66b783ab4ef5831eb-WechatIMG3.jpeg)


### 代码

```java
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int i = 0;
        int j = 0;
        List<int[]> res = new ArrayList();
        while(i<A.length && j<B.length){
            int low = Math.max(A[i][0],B[j][0]);
            int high = Math.min(A[i][1],B[j][1]);
            if(low <= high){
                res.add(new int[]{low,high});
            }
            if(A[i][1] < B[j][1]){
                i++;
            }else if(A[i][1]==B[j][1]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        int[][] resArray = new int[res.size()][2];
        for(int k=0;k<res.size();k++){
            resArray[k] = res.get(k);
        }
        return resArray;
    }
}
```