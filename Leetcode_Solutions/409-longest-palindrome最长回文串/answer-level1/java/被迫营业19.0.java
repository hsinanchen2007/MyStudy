class Solution {
    public int longestPalindrome(String s) {
         HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        for (char c : s.toCharArray()) {
			map.put(c, map.getOrDefault(c, 0)+1);
		}
        int ans = 0;
        for (Character c : map.keySet()) {
        	int value = map.get(c);
			ans+=(value/2*2);
			if(value%2==1&&ans%2==0) {
				ans++;
			}
			
		}
        return ans;
    }
}