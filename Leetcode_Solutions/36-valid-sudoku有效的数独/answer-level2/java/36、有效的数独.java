### 解题思路
方法1：类似于暴力搜索，
        写法1多次遍历整个数独，每一次分别对每一行、每一列、每个box区域进行判断；
        写法2仅遍历整个数独一次，一次实现判断三种情况；
        两种写法的时间复杂度均为n²，因为它们相差平方的常数倍，用时6ms
方法2：利用二维数组分别记录行、列、box的查询结果，遍历数独一次，用时2ms。
方法3：利用位运算，用时2ms。
        与运算：两个数对应bit同为1时，该bit位置为1，否则为0；
        异或运算：两个数对应bit不相同时，该bit位置为1，否则为0。与0异或，结果不变；0与1亦或，结果为1；
        对于本题，分别定义三个int类型（32bit）数据表示行、列、box。对应bit上为1表示已存在对应数
        对于每一个需要判断的新值target，
            1）旧的值old首先右移target位，移位后，第0位上的值即表示target是否存在（0为不存在，1为存在）；
                例：1001000100，表明9，6，2已存在
            2）然后将移位后的值与1相与，判断末位即target是否存在。
                例：target=4，移位后得到100100，末位为0，与1得0，4不存在；
                    target=2，移位后得到10010001，末位为1，与1得1，2存在。
            3）若结果为1，表明target已经存在，返回false；若结果为0，表明target不存在；
            4）不存在时更新val，将target对应的bit置为1；
            5）更新方式：将1左移target位，得到表示target的bit值
                    例：target=4，1左移后得到10000，亦或后得到newValue=1001010100，4加入
### 代码

```java
//写法1：
class Solution {
    public boolean isValidSudoku(char[][] board) {
    //逐行搜索
    HashSet<Character> set = new HashSet<>(); 
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            if(board[i][j] == '.'){
                continue;
            }
            if(set.contains(board[i][j])){
                return false;
            }
            else{
                set.add(board[i][j]);
            }
        }
        set.clear();
    }
    //逐列搜索
    for(int j = 0; j < 9; j ++){
        for(int i = 0; i < 9; i ++){
            if(board[i][j] == '.'){
                continue;
            }
            if(set.contains(board[i][j])){
                return false;
            }
            else{
                set.add(board[i][j]);
            }
        }
        set.clear();
    }
    //在3*3区域中搜索  
    for(int i = 0; i < 9; i += 3){
        int j = 0;
        while(j < 9){
            int n = 1;
            while(n < 4){
                if(set.contains(board[i][j]) || set.contains(board[i+1][j]) || set.contains(board[i+2][j])){
                    return false;
                }
                if(board[i][j] != '.'){
                    set.add(board[i][j]);
                }
                if(board[i + 1][j] != '.'){
                    set.add(board[i + 1][j]);
                }
                if(board[i + 2][j] != '.'){
                    set.add(board[i + 2][j]);
                }
                j ++;
                n ++;
            }
            set.clear();
        }
    }
    return true; 
    }
}
```
```java
//写法2：
class Solution {
    public boolean isValidSudoku(char[][] board) {
    HashSet<Character> row = new HashSet<>();
    HashSet<Character> col = new HashSet<>();
    HashSet<Character> [] box = new HashSet[9];
    //数组中存储HashSet类型的数据，必须要用for再新建一遍，否则box[i]=null，无法与char类型进行比较
    //for循环新建后，box[i]=[]
    for(int i = 0; i<9;i++){
        box[i] = new HashSet<Character>();
    }
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            //0-8个区域
            int index = (i / 3) * 3 + j / 3;  
            if(row.contains(board[i][j]) || col.contains(board[j][i]) || box[index].contains(board[i][j])){
                return false;
            }
            if(board[i][j] != '.'){
                row.add(board[i][j]);
                box[index].add(board[i][j]);
            }
            if(board[j][i] != '.'){
                col.add(board[j][i]);
            }
        }
        row.clear();
        col.clear();
    }
    return true; 
    }
}
```
```java
//方法2
class Solution {
    public boolean isValidSudoku(char[][] board) {
        //10是为了与转换后的0-9对应
        int[][] row = new int[9][10];
        int[][] col = new int[9][10];
        int[][] box = new int[9][10];
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(board[i][j] == '.'){
                    continue;
                }
                int n = board[i][j] - 48;
                if(row[i][n]==1 || col[j][n]==1 || box[(i/3)*3+j/3][n]==1){
                    return false;
                }
                row[i][n] = 1;
                col[j][n] = 1;
                box[(i/3)*3+j/3][n] = 1;
            }
        }
        return true;
    }
}
```
```java
//方法3
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i ++){
            int row = 0;
            int col = 0;
            int box = 0;
            for(int j = 0; j < 9;j ++){
                if(board[i][j] != '.'){
                    int r = board[i][j] - 48;
                    row = newValue(r, row);
                }
                if(board[j][i] != '.'){
                    int c = board[j][i] - 48;
                    col = newValue(c, col);
                }
                if(board[(i/3)*3+j/3][(i%3)*3+j%3] != '.'){
                    int b = board[(i/3)*3+j/3][(i%3)*3+j%3];
                    box = newValue(b, box);
                }
                if(row == -1 || col == -1 || box == -1){
                    return false;
                }
            }
        }
        return true;
    }
    public int newValue(int target, int val){
        return ((val >> target) & 1) == 1 ? -1 : (val ^ (1 << target));
    }
}
```