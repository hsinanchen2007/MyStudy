    int minArray(vector<int>& numbers) {
        int len=numbers.size();
        int left=0,right=len-1;
        while(left<=right)
        {
            if(left==right)
                return numbers[left];
            int mid=(left+right)/2;
            if(numbers[right]==numbers[mid])
            {
                right--;
            }
            else if(numbers[mid]>numbers[right])
            {
                left=mid+1;
            }
            else right=mid;
        }
        return -1;
    }