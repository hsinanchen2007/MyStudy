效率很低，仅供参考，胜在好理解

首先构建字母表对应的位置图，我是用MAP来存储的，key为字母，value为[i,j]坐标
然后是dfs遍历每一种情况，对比找到最小距离

dfs共分为3种情况：
1、使用第一个手指
2、使用第二个手指，并且第二个手指第一次使用
3、使用第二个手指，并且第二个手指使用过

同时使用记忆化搜索进行优化

```
class Solution {
    int res = Integer.MAX_VALUE;
    
    public int minimumDistance(String word) {
        char[][] b = new char[5][6];
        Map<Character,int[]> map = new HashMap<>();
        int index = 0;
        //构建字母对应的坐标
        for(int i=0 ; i<5 ; i++){
            for(int j=0 ; j<6 ; j++){
                map.put((char)(index+'A'),new int[]{i,j});
                ++index;
            }
        }
        return dfs(word,map,1,map.get(word.charAt(0)),new int[]{-1,-1});
    }
    //记忆化搜索存储mem，key为 当前字母index + 第一个手指坐标 + 第二个手指坐标, value为当前情况到达末尾的最小距离
    Map<String,Integer> mem = new HashMap<>();
    
    public int dfs(String word,Map<Character,int[]> map,int index,int[] first,int[] second){
        if(index==word.length()){
            return 0;
        }
        
        char c = word.charAt(index);
        //拼接key值，记忆化搜索
        String str = String.valueOf(index) +"*" +first[0] +"*"+ first[1] + "*"+second[0] +"*"+ second[1];
        if(mem.containsKey(str)){
            return mem.get(str);
        }
        //得到下一步坐标
        int[] next = map.get(c);

        //使用第一个手指需要的距离
        int diff1 = Math.abs(first[0]-next[0]) + Math.abs(first[1]-next[1]);
        //递归遍历持续使用第一个手指的情况
        int len1 = dfs(word,map,index+1,next,second) + diff1;
        int len2 = 0;
        //第二个手指分两种情况
        if(second[0]>=0){  //1、第二个手指使用过，需要计算距离         
            int diff2 = Math.abs(second[0]-next[0]) + Math.abs(second[1]-next[1]);
            len2 = dfs(word,map,index+1,first,next) + diff2;
        } else{//第二个手指没有使用过，不需要计算距离
            len2 = dfs(word,map,index+1,first,next);
        }
        //存储最小值
        mem.put(str,Math.min(len1,len2));

        return Math.min(len1,len2);
    }
}
```
