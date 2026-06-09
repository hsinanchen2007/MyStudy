
![Image.jpg](https://pic.leetcode-cn.com/add3252c0ca68be7852f8517004b9aec552ec30b62f1f84695b3408960815951-Image.jpg)

char nextGreatestLetter(char* letters, int lettersSize, char target){
    int left,right,mid;
    if(target>=letters[lettersSize-1] || target<letters[0])
    {
        return letters[0];
    }
    left=0;
    right=lettersSize;
    while(left<right)
    {
        mid=left+(right-left+1)/2;
        if(target<letters[mid])
        {
            right=mid-1;
        }
        else 
        {
            left=mid;
        }
    }
     return letters[left+1];
}

