68 / 68 个通过测试用例
状态：通过
执行用时：0 ms


class Solution {
    public boolean isArmstrong(int N) {
        int result = 0;
        int num = N;
        
        int i=0; 
        for(;num>0; i++) {
            num = num/10;
        }
        
        num = N;
        
        while(num>0) {
        	result += calculate(num%10, i);
        	num /= 10;
        }

        return (result == N);
    }
    
    public int calculate(int n, int times) {
        int result = 1;
        int t = times;
        while(t>0) {
        	result *= n;
        	t--;
        }

        return result;
    }
}