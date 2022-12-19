### 解题思路
通俗易懂

### 代码

```c

int hash(char key)
{
    return key - 'A';
}
int romanToInt(char * s){
    int hashtable[26] = { 0 };
    hashtable[hash('I')] = 1;
    hashtable[hash('V')] = 5;
    hashtable[hash('X')] = 10;
    hashtable[hash('L')] = 50;
    hashtable[hash('C')] = 100;
    hashtable[hash('D')] = 500;
    hashtable[hash('M')] = 1000;
    int n = strlen(s);
    int num = 0;
    for(int i = 0; i < n; i++){
        int next = i + 1;
        if(next < n && hashtable[hash(s[next])] > hashtable[hash(s[i])]){
            num -= hashtable[hash(s[i])];
        } else{
            num += hashtable[hash(s[i])];
        }
    }
    return num;
}


```