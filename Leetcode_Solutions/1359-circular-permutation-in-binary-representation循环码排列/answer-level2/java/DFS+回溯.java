
DFS搜索满足结果的列表
根据异或的特点，与1异或等于对该位取反，就能得到与当前数只有一位不同的数，
如果得到得数已经出现过，那么将1左移，对当前数下一位取反，直到得到没有出现
的数为止
```
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer>list=new ArrayList<>();
        boolean[]visited=new boolean[(int)(Math.pow(2,n))];
        list.add(start);visited[start]=true;
        bracket(list,start,visited,visited.length,start);
        return list;
    }
    private void bracket(List<Integer>list,int endNum,boolean[]visited,int length,int start){
        if (list.size()==length){
            int res=start^list.get(length-1),count=0;
            while (res!=0){res&=(res-1);count++;if (count>1)break;}
            if (count==1)return;
        }
        int nextNum=0;
        int xorN=1;
        while (xorN!=0){
            nextNum=endNum^xorN;
            if (nextNum<length&&!visited[nextNum])
                break;
            xorN=xorN<<1;
        }
        list.add(nextNum);
        visited[nextNum]=true;
        bracket(list,nextNum,visited,length,start);
        if (list.size()==length)return;
        visited[nextNum]=false;
        list.remove(list.size()-1);
    }
}
```
