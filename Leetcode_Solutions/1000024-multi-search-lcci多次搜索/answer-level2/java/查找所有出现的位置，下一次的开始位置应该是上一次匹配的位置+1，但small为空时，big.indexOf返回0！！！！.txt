### 解题思路
此处撰写解题思路
**字符串查找前，一定先要进行非空判断，因为为""时，indexOf返回为0！！！**
`再次强调：当不能完成类型转换时，就额外申请一个变量！！！`
![Snipaste_2020-03-18_18-42-41.jpg](https://pic.leetcode-cn.com/94cf4d7b596b2162c4b525fe43bc13a9066e0a62614f679cee5cd40846cfd476-Snipaste_2020-03-18_18-42-41.jpg)

### 代码

```java
class Solution {
    public int []  getAllStartPos(String big,String small){
        List<Integer> res=new ArrayList<>();
        if(small.length()==0) return new int[0];
        int index=big.indexOf(small);
        while(index!=-1){
            res.add(index);
            index=big.indexOf(small,index+1);
        }
        int [] ans=new int[res.size()];
        for(int i=0;i<res.size();i++){
            ans[i]=res.get(i);
        }
        return ans;
    }
    public int[][] multiSearch(String big, String[] smalls) {//全部查找。
        List<int[]> res=new ArrayList<>();
        for(int i=0;i<smalls.length;i++){
            res.add(getAllStartPos(big,smalls[i]));
        }
        return res.toArray(new int[0][]);

    }
}
```