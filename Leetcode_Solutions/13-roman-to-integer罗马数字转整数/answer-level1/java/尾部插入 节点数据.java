class Solution {
    public int romanToInt(String s) {
       
        String newS = s + '0';
        HashMap<Object, Integer> map = new HashMap<>();
        map.put('0',0);
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);

        Integer currect = map.get(newS.charAt(0));
        Integer next = null;
        int sum =0;
        for (int i=0;i<s.length();){
            next = map.get(newS.charAt(i+1));
            if (next > currect){
                sum += next - currect;
                i +=2;
                currect = map.get(newS.charAt(i));
            }else {
                sum += currect;
                currect = next;
                i++;
            }
        }

        return sum;
    }
}