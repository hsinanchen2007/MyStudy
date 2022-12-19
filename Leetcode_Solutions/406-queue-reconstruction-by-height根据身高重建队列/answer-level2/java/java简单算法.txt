### 解题思路
此处撰写解题思路
先写一个比较器，将people数组按h递减，k递增排序，然后开一个list数组，按照k值将其存入数组中。
然后存到二维数组中即可。
### 代码

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        if(people==null||people.length==0||people[0].length==0) return new int[0][0]; 
        Comparator<int[]> cmp=new Comparator<int[]>(){
            public int compare(int[]a,int[]b){
                if(a[0]==b[0]) return a[1]-b[1];
                return b[0]-a[0];
            }
        };
        Arrays.sort(people,cmp);
        int n=people.length;
        List<int[]> tmp=new ArrayList<>();
        for(int i=0;i<n;i++){
              tmp.add(people[i][1],new int[]{people[i][0],people[i][1]});
        }
        int[][]ret=new int[n][2];
        for(int i=0;i<n;i++){
            ret[i][0]=tmp.get(i)[0];
            ret[i][1]=tmp.get(i)[1];
        }
        return ret;


    }
}
```