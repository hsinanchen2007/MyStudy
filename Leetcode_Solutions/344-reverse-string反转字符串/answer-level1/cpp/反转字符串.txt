 //典型的双指针解法
//还是标准的双指针解法, 一个指针指向末尾 一个指针指向头部
        int left = 0;
        int right = s.size() - 1;
        while ( left < right ) {
            char temp;
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }