这是一个简单的图，所以我们可以利用深度优先搜索
具体方法是，当前我们进入第i个门，可以拿到j..k的钥匙，我们就可以挨个去找钥匙可以开的门，开完所有门，如果还有剩下的门没开，那么就不满足题意了

于是，这里加入了isVisited数组，来表示第i个门是不是已经进去过了，如果进去过了，那我们就不再进入这个门
流程如下:
(1)遍历所有能进去的门
(2)遍历isVisited，如果出现isVisited[i] == false的情况，就表示门没打开过，那也就说明这个门打不开。

```
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int N = rooms.size();

        boolean[] isVisited = new boolean[N];
        reach(rooms, isVisited, 0);

        for(boolean visit : isVisited){
            if(!visit) return false;
        }

        return true;
    }

    private void reach(List<List<Integer>> rooms, boolean[] isVisited, int index){

        List<Integer> keys = rooms.get(index);
        isVisited[index] = true;

        for(int key : keys){
            if(isVisited[key]) continue;
            reach(rooms, isVisited, key);
        }
    }

```
