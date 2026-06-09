class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        char[] chars = s.toCharArray();
        Integer temp = 0;
        for (int i = 0; i < chars.length; i ++){
            if (map.containsKey(chars[i])) {
                temp = map.get(chars[i]) ;
                temp ++;
                map.put(chars[i], temp);
            } else {
                map.put(chars[i], 1);
            }
        }
        int[] nums = new int[map.size()];
        char[] whichChar = new char[map.size()];
        Iterator entrys = map.entrySet().iterator();
        int i = 0;
        while (entrys.hasNext()){
            Map.Entry entry = (Map.Entry)entrys.next();
            nums[i] = (Integer) entry.getValue();
            whichChar[i] = (Character) entry.getKey();
            i ++;
        }
        quickSort(nums, whichChar, 0, nums.length - 1);
        StringBuilder result = new StringBuilder();
        for (int k = 0; k < nums.length; k ++) {
            for (int j = 0; j < nums[k]; j ++) {
                result.append(whichChar[k]);
            }
        }
        return result.toString();
    }
    public void quickSort(int[] nums, char[] whichChar, int l, int r) {
        if (l >= r)
            return;
        int i = l;
        int j = r;
        int key = nums[i];
        char keyChar = whichChar[i];
        while (i < j) {
            while (i < j && nums[j] < key) {
                j --;
            }
            if (i < j) {
                nums[i] = nums[j];
                whichChar[i] = whichChar[j];
                i ++;
            }
            while (i < j && nums[i] >= key) {
                i ++;
            }
            if (i < j) {
                nums[j] = nums[i];
                whichChar[j] = whichChar[i];
                j --;
            }
        }
        nums[i] = key;
        whichChar[i] = keyChar;
        quickSort(nums, whichChar, l, i - 1);
        quickSort(nums, whichChar, i + 1, r);
    }
}