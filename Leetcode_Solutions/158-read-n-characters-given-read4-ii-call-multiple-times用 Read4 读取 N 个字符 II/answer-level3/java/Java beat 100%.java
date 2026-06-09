
   
// 備份，因為有可能還沒用完
char[] temp = new char[4];

//同上，紀錄用到哪一位
int index = 0;
int count = 0;

public int read(char[] buf, int n) {
    
    int i = 0; //用來返回總共處理了幾個

    while (i < n) {

        //當用完時要從新讀，並把index歸0
        if (index == count) {
            count = read4(temp);
            index = 0;
        }

        //添加近buff
        while (i < n && index < count) {
            buf[i++] = temp[index++];
        }

        //當還沒處理完目標的n個，且read4已經讀到底了，就出去。
        if (i < n && count < 4) break;

    }
    return i;
}
