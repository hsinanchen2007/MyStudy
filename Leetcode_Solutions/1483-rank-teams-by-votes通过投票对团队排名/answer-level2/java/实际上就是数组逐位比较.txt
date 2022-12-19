![image.png](https://pic.leetcode-cn.com/2ac1f0e3ba208f5e9c75882ff8956f2a3cdfd551fe3ee98fa5ab4efd2b6a7c13-image.png)
实际上这道题考察就是数组的逐位比较
```
public String rankTeams(String[] votes) {
    int rowNum = votes.length;
    int colNum = votes[0].length();
    if (rowNum==0){return "";}

    StringBuilder res = new StringBuilder();
    //得到每个字符在各个排名中的次数
    HashMap<Character, int[]> myHashMap = new HashMap<>();
    for (int row=0; row<rowNum;row++){
        for (int rank=0;rank<colNum;rank++){
            //rank即为排名
            char curKey = votes[row].charAt(rank);
            if (myHashMap.containsKey(curKey)) {
                int[] ints = myHashMap.get(curKey);
                ints[rank] += 1;
            }
            else {
                int[] curValue = new int[colNum];
                curValue[rank] = 1;
                myHashMap.put(curKey, curValue);
            }
        }
    }
    //myTmpHashMap按照value值进行排序
    List<Map.Entry<Character, int[]>> list =
            new ArrayList<Map.Entry<Character, int[]>>(myHashMap.entrySet()); //转换为list
    list.sort(new Comparator<Map.Entry<Character, int[]>>() {
        @Override
        public int compare(Map.Entry<Character, int[]> o1, Map.Entry<Character, int[]> o2) {
            //定义返回值，o1<o2 -1,o1=01 0, o1>o2 1
            int res = 0;
            int[] o1Vaule = o1.getValue();
            int[] o2Value = o2.getValue();
            //比较数组o1和o2
            for (int i=0;i<o1Vaule.length;i++){
                if (o1Vaule[i]>o2Value[i]){
                    return -1;
                }
                else if (o1Vaule[i]<o2Value[i]){
                    return 1;
                }
            }
            return o1.getKey().compareTo(o2.getKey());
        }

    });
    for (int i = 0; i < list.size(); i++) {
        res.append(list.get(i).getKey());
    }
    return res.toString();
}
```
解题思路是先构造一个hashMap，key值即为队名，value值为一个数组，每个index上的值即该队有多少次排名index+1。则我们只需重写hashMap的比较器即可。不过注意比较器的返回值。