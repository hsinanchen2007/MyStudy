```
class Solution {
    
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people,new Comparator<int[]>(){
            @Override
            public int compare(int[] o1,int[] o2){
                if(o1[0]==o2[0]){
                    return o1[1] > o2[1] ? 1:-1;
                }else{
                    return o2[0] > o1[0] ? 1:-1;
                }
            }
        });
        List<int[]> res = new LinkedList<int[]>();
        for(int i = 0;i<people.length;i++){
            res.add(people[i][1],people[i]);
        }
        int[][] resArray = new int[people.length][2];
        for(int i = 0;i<resArray.length;i++){
            resArray[i][0] = res.get(i)[0];
            resArray[i][1] = res.get(i)[1];

        }
        return resArray;

    }
}
```
