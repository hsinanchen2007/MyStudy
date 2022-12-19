用位运算处理比较简洁。棋盘可以用二进制编码成9位，整个棋盘只有8种胜利条件（三纵三横两个对角线）。

如图↓
```
  g a b c h
    x x x d
    x x x e
    x x x f
```

这三种局势可编码为：

```
int a = 0b100100100;
int b = 0b010010010;
int c = 0b001001001;
int d = 0b111000000;
int e = 0b000111000;
int f = 0b000000111;
int g = 0b100010001;
int h = 0b001010100;
``` 

同时分别用两个变量保存棋手A和B的落子情况。

并且每次落子之后，遍历是上面8个胜利条件，只要有一个满足就算胜。

其中，落子通过位或运算，判断胜利通过位与运算。

落子的位置是将0b1向左移(2 - x) * 3 + (2 - y) = 8 - 3 * x - y位。

判断胜利（例如局面a）条件为((落子&a)==a)。

```
class Solution {
public:
    int correct_mask[8] =  {0b100100100, 0b010010010, 0b001001001, 0b111000000, 
                            0b000111000, 0b000000111, 0b100010001, 0b001010100};
    string tictactoe(vector<vector<int>>& moves) {
        int counter = 0;
        int map_A = 0x000000000;
        int map_B = 0x000000000;
        for (auto step = moves.begin(); step != moves.end(); ++step){
            int x = (*step)[0];
            int y = (*step)[1];
            int shift = 8 - 3 * x - y;
            if (counter % 2 == 0){ // for playerA
                map_A = map_A | (0b1<<shift);
            }else{ // for playerB
                map_B = map_B | (0b1<<shift);
            }
            // check wins
            for (int i = 0; i < 8; ++i){
                if ((map_A & correct_mask[i]) == correct_mask[i]){
                    return "A";
                }else if((map_B & correct_mask[i]) == correct_mask[i]){
                    return "B";
                }
            }
            counter += 1;
        }
        if (counter == 9){
            return "Draw";
        }else{
            return "Pending";
        }
    }
};
```