两个指针p1，p2，用来记录不连续子串的首末位置，但是为什么内存消耗值击败了13%？

public int lengthOfLongestSubstring(String s) {
        if((s==null)|(s.length()==0))return 0;
        if (s.length()==1)return 1;
        int p1=0, p2=0, max=0;
        for (int i=1; i<s.length(); i++){
            for (int j=i-1; j>=p1; j--){
                if (s.charAt(i)==s.charAt(j)){
                    if (max<(i-p1))max=i-p1;
                    p1=j+1;
                    break;
                }
                else if (j==p1&&max<(i-p1+1)) max=i-p1+1;
            }
        }
        System.out.println(max);
        return max;