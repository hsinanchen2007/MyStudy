按照下列的顺序进行检测,可以根据加粗的字母来确定该数字的个数
**z**ero,t**w**o,si**x**,ei**g**ht->**s**even->fi**v**e->**f**our->t**h**ree->n**i**ne->o**n**e
```
class Solution {
    public String originalDigits(String s) {
        int i, j;
        int[] map, nums;
        String answer;

        map = new int[26];
        nums = new int[10];
        answer = "";
        for(i = 0; i < s.length(); i++)
            map[s.charAt(i)-'a']++;
        //zero
        nums[0] = map['z'-'a'];
        //two
        nums[2] = map['w'-'a'];
        //six
        nums[6] = map['x'-'a'];
        //eight
        nums[8] = map['g'-'a'];
        //seven
        nums[7] = map['s'-'a'] -nums[6];
        //five
        nums[5] = map['v'-'a'] - nums[7];
        //four
        nums[4] = map['f'-'a'] - nums[5];
        //three
        nums[3] = map['h'-'a'] - nums[8];
        //nine
        nums[9] = map['i'-'a'] - nums[5] - nums[6] - nums[8];
        //one
        nums[1] = map['n'-'a'] - nums[7] - nums[9] * 2;

        for(i = 0; i < 10; i++)
            for(j = 0; j < nums[i]; j++)
                answer += i;
        return answer;
    }
}
```

