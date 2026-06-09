```
1、使用HashMap 统计相同元素的个数
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck == null || deck.length <= 1) {
            return false;
        }
        int numbers[] = new int[10000];
        Map<Integer, Integer> groupMap = new HashMap<>();
        for(int i = 0; i< deck.length; i++) {
            numbers[deck[i]]++;
        }
        int minCommonDisivor = -1; 
        for(int j = 0; j < numbers.length; j++) {
            if(numbers[j]==0) {
                continue;
            } else if(minCommonDisivor ==-1) {
                minCommonDisivor = numbers[j];
            } else {
                minCommonDisivor = gcd(numbers[j], minCommonDisivor);
                if(minCommonDisivor <2) {
                    return false;
                }
            }
        }
        return true;
    }
    private int gcd(int a, int b) {
        return a == 0?b:gcd(b%a, a);
    }
}
2 使用数组 统计相同元素的个数
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck == null || deck.length <= 1) {
            return false;
        }
        int numbers[] = new int[10000];
        for(int i = 0; i< deck.length; i++) {
            numbers[deck[i]]++;
        }
        int minCommonDisivor = -1; 
        for(int j = 0; j < numbers.length; j++) {
            if(numbers[j]==0) {
                continue;
            } else if(minCommonDisivor ==-1) {
                minCommonDisivor = numbers[j];
            } else {
                minCommonDisivor = gcd(numbers[j], minCommonDisivor);
                if(minCommonDisivor <2) {
                    return false;
                }
            }
        }
        return true;
    }
    private int gcd(int a, int b) {
        return a == 0?b:gcd(b%a, a);
    }
}
```
