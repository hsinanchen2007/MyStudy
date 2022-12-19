public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        int[] num = {};
        Console.Write(num.Length);
        for(int i = 0;i<nums1.Length;i++)
        {
            for(int j = 0; j<nums2.Length;j++)
            {
                if(nums1[i] == nums2[j])
                {
                    bool target = true;
                    for(int k = 0; k < num.Length ;k++)
                    {
                        
                        if(nums1[i] == num[k])
                        {
                            target = false;
                            break;
                        }
                        
                    
                    }
                    if(target)
                        {
                            num = num.Concat(new int[] {nums1[i]}).ToArray();
                        }
                }
                
            }
            
        }
        return num;
    }
}