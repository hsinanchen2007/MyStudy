### 解题思路
广度优先遍历

### 代码

```csharp

//广度优先遍历
class HState {
    public int step = 0;
    public List<int> boardState;
    public int zeroPos;
    public bool CheckOK(){
        for (var i = 0; i < boardState.Count()-1; i++){
            if(boardState[i] != (i+1) ) return false;
        }
        return true;
    }
    public int GetKey(){
        var i = 1;
        var sum = 0;
        foreach(var v in boardState){
            sum += v * i;
            i *= 6;
        }
        return sum;
    }
    public List<HState> Next(){
        var r = zeroPos / 3;
        var col = zeroPos % 3;
        var ret = new List<HState>();
        if(col > 0){
            var left = col - 1;
            var s = new HState();
            ret.Add(s);
            s.boardState = new List<int>(boardState);
            var zp = left + r * 3;
            s.boardState[zp] = 0;
            s.boardState[zeroPos] = boardState[zp];
            s.zeroPos = zp;
            s.step = step + 1;
        }
        if(col < 2){
            var right = col + 1;
            var s = new HState();
            ret.Add(s);
            s.boardState = new List<int>(boardState);
            var zp = right + r * 3;
            s.boardState[zp] = 0;
            s.boardState[zeroPos] = boardState[zp];
            s.zeroPos = zp;
            s.step = step + 1;
        }
        if(r > 0){
            var down = r - 1;
            var s = new HState();
            ret.Add(s);
            s.boardState = new List<int>(boardState);
            var zp = col + down * 3;
            s.boardState[zp] = 0;
            s.boardState[zeroPos] = boardState[zp];
            s.zeroPos = zp;
            s.step = step + 1;
        }
        if(r < 1){
            var up = r + 1;
            var s = new HState();
            ret.Add(s);
            s.boardState = new List<int>(boardState);
            var zp = col + up * 3;
            s.boardState[zp] = 0;
            s.boardState[zeroPos] = boardState[zp];
            s.zeroPos = zp; 
            s.step = step + 1;
        }
        return ret;
    }
}
class HuaRongDao{
    public int SlidingPuzzle(int[][] board) {
        var initState = new HState();
        initState.boardState = new List<int>();
        for (var i = 0; i < board.Length; i++){
            foreach(var v in board[i]){
                initState.boardState.Add(v);
                if(v == 0){
                    initState.zeroPos = initState.boardState.Count() - 1;
                }
            }
        }
        var openQ = new Queue<HState>();
        var hash = new HashSet<int>();
        openQ.Enqueue(initState);
        hash.Add(initState.GetKey());
        while (openQ.Count > 0)
        {
            var fir = openQ.Dequeue();
            if (fir.CheckOK()) return fir.step;
            var ne = fir.Next();
            foreach (var n in ne)
            {
                var k = n.GetKey();
                if (!hash.Contains(k))
                {
                    hash.Add(k);
                    openQ.Enqueue(n);
                }
            }
        }
        return -1;
    }
}

public class Solution {
    public int SlidingPuzzle(int[][] board) {
        var sp = new HuaRongDao();
        return sp.SlidingPuzzle(board);
    }
}
```