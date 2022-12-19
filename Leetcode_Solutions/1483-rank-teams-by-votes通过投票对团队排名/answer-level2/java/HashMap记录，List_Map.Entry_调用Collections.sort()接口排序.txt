## 思路
思路都已经包括在代码之中
```java
class Solution {
    public String rankTeams(String[] votes) {
        //用于记录：每个字符对应的数组记录着每次的rank次数
        Map<Character,int[]> map = new HashMap<>();
        //第一次还没有创建数组，先遍历一遍初始化map并创建数组
        for(int i = 0;i < votes[0].length();i++) {
            int[] rank = new int[26];
            rank[i]++;
            map.put(votes[0].charAt(i),rank);
        }
        //记录，第一个已经记录过了
        for(int i = 1;i < votes.length;i++) {
            for(int j = 0;j < votes[i].length();j++) {
                map.get(votes[i].charAt(j))[j]++;
            }
        }
        //将map拆分成entry放在list里面
        List<Map.Entry<Character,int[]>> list = new ArrayList<>(map.entrySet());

        //调用接口排序
        Collections.sort(list,new Comparator<Map.Entry<Character,int[]>>() {
        //想让a排在b前，返回值必须为负数。
        //而a排在b前的条件是：a的rank“分数”比b高
            public int compare(Map.Entry<Character,int[]> a,
                Map.Entry<Character,int[]> b){
                for(int i = 0;i < 26;i++) {
                    if(a.getValue()[i] > b.getValue()[i]){
                        return -1;
                    }else if(a.getValue()[i] < b.getValue()[i]){
                        return 1;
                    }
                }
                //rank分都一样的情况，比“血统”。ascii码靠前的比较“强”
                return a.getKey() - b.getKey();
            }
        });
        //拼接一下结果
        StringBuilder ans = new StringBuilder();

        for(int i = 0;i < list.size();i++){
            ans.append(list.get(i).getKey());
        }

        return ans.toString();
    }
}
```
