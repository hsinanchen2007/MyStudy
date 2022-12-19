bool judgeCircle(char * moves){
    int step_num = strlen(moves);
    int up = 0, left = 0;
    for (int i = 0; i < step_num; ++i) {
        if (moves[i] == 'U') up++;
        if (moves[i] == 'D') up--;
        if (moves[i] == 'L') left++;
        if (moves[i] == 'R') left--;
    }
    return ((left == 0) && (up == 0));
}
两个方向最终结果都是0就是回到了原点