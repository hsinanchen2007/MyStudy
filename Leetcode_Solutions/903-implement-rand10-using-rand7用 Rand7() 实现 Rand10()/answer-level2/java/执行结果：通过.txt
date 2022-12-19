执行用时 :
11 ms
, 在所有 Java 提交中击败了
71.36%
的用户
内存消耗 :
45.6 MB
, 在所有 Java 提交中击败了
26.19%
的用户
```
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    
    int addSeed(int seed1, int seed2){
        return seed1+seed2*7;
    }
    public int rand10() {
        int result = 0;
        while((result=addSeed(rand7(),rand7()))>47);
        return (result-8)/4+1;
    }
}
```
