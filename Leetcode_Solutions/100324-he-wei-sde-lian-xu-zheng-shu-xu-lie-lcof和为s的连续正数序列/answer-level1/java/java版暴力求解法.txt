### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]>list=new ArrayList<>();
        for(int i=1;i<target;i++){
            List<Integer>tmp=new ArrayList();
            int count=i;
            tmp.add(i);
            for(int j=i+1;i<target && count<target;j++){
                count+=j;
                tmp.add(j);
                if(count==target){
                    int [] tmpRes=new int[tmp.size()];
                    for(int k=0;k<tmp.size();k++){
                        tmpRes[k]=tmp.get(k);
                    }
                    list.add(tmpRes);   
                }
            }
        }
        return list.toArray(new int[list.size()][]);
    }
}
```