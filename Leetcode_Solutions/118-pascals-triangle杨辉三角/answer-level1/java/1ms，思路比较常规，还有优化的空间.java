### 解题思路


### 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        if(numRows<=0) return ans;
        List<Integer> fir=new ArrayList<Integer>();
        fir.add(1);
        ans.add(fir);
        int[] temp={0,1,0};
        for(int i=1;i<numRows;i++){
            List<Integer> list=new ArrayList<Integer>();
            for(int j=0;j<temp.length-1;j++){
                list.add(temp[j]+temp[j+1]);
            }
            ans.add(list);
            temp=new int[temp.length+1];
            temp[0]=0;
            temp[temp.length-1]=0;
            int k=1;
            for(int n:list){
                temp[k++]=n;
            }
        }

        return ans;
    }
}
```