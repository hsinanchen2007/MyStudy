public void reverseString(char[] s) {
    int len = s.length;
    int i = 0, j = len -1;
    while (i < j) {
        swap(s, i, j);
        i ++;
        j --;
    }
}
    
public void swap(char[] chars, int i, int j) {
    char tmp = chars[i];
    chars[i] = chars[j];
    chars[j] = tmp;
}