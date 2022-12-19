### 解题思路
https://www.zhihu.com/people/god-jiang

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder==null||postorder.length==0){
            return true;
        }
        if(postorder.length==1){
            return true;
        }
        return judge(postorder,0,postorder.length-1);
    }
    public boolean judge(int[] postorder,int start,int end){
        if(start>=end){
            return true;
        }
        int i=start;
        while(postorder[i]<postorder[end]){
            i++;
        }
        for(int j=i;j<end;j++){
            if(postorder[j]<postorder[end]){
                return false;
            }
        }
        return judge(postorder,start,i-1)&&judge(postorder,i,end-1);
    }
}
```