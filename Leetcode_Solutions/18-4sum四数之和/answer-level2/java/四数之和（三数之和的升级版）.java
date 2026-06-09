和三数之和解法类似，依然使用双指针解法，只不过在三数之和的基础上在套一层for循环
public class Main{
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.println("输入数组长度");
        int len=scanner.nextInt();
        System.out.println("输入数组");
        int[] nums=new int[len];
        for(int i=0;i<len;i++){
            nums[i]=scanner.nextInt();
        }
        System.out.println("输入目标值");
        int target=scanner.nextInt();
        System.out.println(fourSum(nums,target));
    }
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> lists=new ArrayList<>();
        if(nums==null||nums.length<4){
            return lists;
        }
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
            for (int j = i + 1; j < nums.length; j++) {
                if(j>i+1&&nums[j]==nums[j-1]) continue;//去重
                int left = j + 1;
                int right = nums.length - 1;
                while (left< right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        lists.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        while (left< right && nums[left] == nums[left+ 1]) {//去重
                            left++;
                        }
                        while (left< right && nums[right] == nums[right - 1]) {//去重
                            right--;
                        }
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return lists;
    }
}