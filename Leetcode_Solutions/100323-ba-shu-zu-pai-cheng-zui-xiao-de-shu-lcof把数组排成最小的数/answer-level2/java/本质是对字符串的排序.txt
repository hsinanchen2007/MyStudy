class Solution {
    public String minNumber(int[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf)
                .sorted((str1, str2) -> (str1 + str2).compareTo((str2 + str1)))
                .reduce((s, s2) -> s + s2)
                .get();
    }
}