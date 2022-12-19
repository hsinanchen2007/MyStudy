### 解题思路
此处撰写解题思路

### 代码

```java


class Solution {
    // 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
    // 1. 路径：做出的选择
    // 2. 选择列表：当前可以做的选择
    // 3. 结束条件：到达决策树底层，无法再做选择的条件
    public String[] permutation(String s) {
        if(s.length()==0)return new String[0];
        
        ArrayList<String> ans = new ArrayList<>();
        char[] array = s.toCharArray();
        Arrays.sort(array);
        LinkedList<Character> track = new LinkedList<>();
        //boolean默认false
        boolean[] visit = new boolean[s.length()]; 

        backTrack(ans, array, track, visit);
        return ans.toArray(new String[ans.size()]);
    }
    
    //ans是ArrayList形式的结果值，array是选择列表即s串的元素，
    //track为当前排列，visit[i]表示array[i]是否访问过
    public void backTrack(ArrayList<String> ans, char[] array, LinkedList<Character> track, boolean[] visit ){
        //判断是否到达底层->树高度为array.length
        if(track.size()==array.length){
            //到达底层则将track加入到ans中
            StringBuilder merge = new  StringBuilder();
            for(char c:track){
                merge.append(c);
            }
            ans.add(merge.toString());
            return;
        }
        //选择列表
        for(int i = 0; i < array.length; i++){
            //如果当前字符等于上一次的字符并且上一次的索引已经访问过，那么本次遍历跳过
            if(i>0&&!visit[i-1]&&array[i]==array[i-1])continue;
            
            //当前array[i]未访问时
            if(!visit[i]){
                visit[i] = true;
                track.addLast(array[i]);

                backTrack(ans,array,track,visit);

                //递归完后需要把track和visit恢复到一开始的值
                track.removeLast();
                visit[i] = false;
            }
        }
        
    }
}
```