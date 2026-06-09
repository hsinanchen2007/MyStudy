```
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] temp = new int[3];
        temp[0] = a;
        temp[1] = b;
        temp[2] = c;
        Arrays.sort(temp);
        a = temp[0];
        b = temp[1];
        c = temp[2];
        int[] result = new int[2];
        int x = b-a-1;
        int y = c-b-1;
        if(x==0&&y==0) return result;
        if(x>1&&y>1) result[0]=2;
        else result[0]=1;
        result[1] = x+y;        
        return result;
    }
}
```
