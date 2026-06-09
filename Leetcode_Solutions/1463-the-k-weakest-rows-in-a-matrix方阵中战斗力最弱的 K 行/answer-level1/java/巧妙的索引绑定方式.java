![image.png](https://pic.leetcode-cn.com/83eda3866e4f6827f03deaab9e5c9709ddb2991153b2ab8636df353232bc9c2d-image.png)
- 这是一道比较经典的索引绑定题型，每一行都是1在前，0在后排序好的，每一行的战斗力非常容易求得。但题中最后要求返回的是行的索引，所以需要将每行的索引和战斗力绑定起来，并且在排序战斗力的过程中索引和战斗力是对应的。
- 绑定的方式是多样的，最容易理解的可能就是使用Map进行绑定。map绑定的方式比较慢，并且所需的内存多。这里介绍一种比较巧妙的绑定方式。只需要将每行的战斗力乘一个很大的数之后加上这一行的索引，足够大的乘数保证了乘完之后战斗力的排序不受行索引的影响。在排序完之后也可以方便的恢复行索引，只需要对乘的数取模就行了。
- java代码的实现：
```
public int[] solution(int[][] mat,int k){
        int len = mat.length;
        //int len1 = mat[0].length;
        int[] arr = new int[len];
        for(int i =0;i<len;i++){
            arr[i] = getW(mat[i])*len+i;
        }
        //对arr进行排序
        Arrays.sort(arr);
        int[] ans = new int[k];
        for(int i =0;i<k;i++){
            ans[i] = arr[i]%len;
        }
        return ans;
}
//求行战斗力
public static int getW(int[] a){
        for(int i = 0;i<a.length;i++){
            if(a[i]==0){
                return i;
            }
        }
        return a.length;
}

```
