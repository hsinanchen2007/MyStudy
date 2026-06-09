```
public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> nums = new LinkedList<>();
        for(;left<=right;left++){
            int sum = 0;
            for(int a = 10000;a>=1;a/=10){
                if(a>left) continue;
                int n = (left-sum)/a;
                if(n==0) break;
                if(left%n!=0) break;
                sum += (n*a);
                if(a==1) nums.add(left);
            }
        }
        return nums;
    }
```
