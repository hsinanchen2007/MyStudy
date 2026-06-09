### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return verify(postorder,0,postorder.length-1);
    }

    //1 3 2 6 5
    //验证数组中l - r的数据是否满足后序遍历
    public boolean verify(int[] arr,int l,int r){
        if(l>r || l==r)
            return true;
        //根节点值
        int rootVal = arr[r];
        //循环找到第一个比 根值 小的数，就是左节点
        int cur = r-1;
        while(cur>=l && arr[cur]>rootVal){
            cur--;
        }
        //l - cur是左子树，cur+1 - r-1是右子树
        //判断 l - cur是不是都小于 根节点得值
        for(int i = l;i<cur;i++){
            if(arr[i]>rootVal)
                return false;
        }
        //判断左子树，右子树是不是满足条件。
        return verify(arr,l,cur)&&verify(arr,cur+1,r-1);
    }
}
```