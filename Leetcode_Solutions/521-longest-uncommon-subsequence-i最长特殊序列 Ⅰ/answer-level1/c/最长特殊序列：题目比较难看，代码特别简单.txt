![image.png](https://pic.leetcode-cn.com/361abf85a64c51e6d003664475f3559e0e5851085b27396f32b9c83a1df563b0-image.png)

/*
    题目理解：
    1.两个字符串A,B，找出这样一个字符串，只能是A的子串，不能是B的子串，或者反过来；
    2.找到这样的最长子串，最长子串一定是A或者B；
    3.只有A=B时，才会返回-1；
*/
int findLUSlength(char * a, char * b){
    
    if (0 == strcmp(a, b))
    {
        return -1;
    }
    
    if (strlen(a) >= strlen(b))
    {
        return strlen(a);
    }
    
    return strlen(b);
}