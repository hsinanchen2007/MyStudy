太简单，官方都不给答案的
public void severseString(char[] str) {
    char c;
    for (int i = 0, j = str.length - 1; i < j; i ++, j --){
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}