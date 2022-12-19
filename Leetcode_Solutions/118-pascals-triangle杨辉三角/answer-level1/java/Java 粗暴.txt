```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        if(numRows<=0){
            return Collections.EMPTY_LIST;
        }
        
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> one = Arrays.asList(new Integer[]{1});
        result.add(one);
        if(numRows!=1){
            List<Integer> two = Arrays.asList(new Integer[]{1,1});
            result.add(two);
            for(int i = 2;i<numRows;i++){
                List<Integer> previous = result.get(i-1);
                int size = i+1;
                Integer[] temp = new Integer[size];
                temp[0]=1;
                temp[i]=1;
                for(int j =1;j<i;j++){
                    temp[j]=previous.get(j)+previous.get(j-1);
                }
                result.add(Arrays.asList(temp));
            }
        }
        
        return result;
    }
}
```
