```
    public boolean isOneBitCharacter(int[] bits) {
        int begin = 0;
        while (begin < bits.length) {
            if (bits[begin] == 1)
                begin += 2;
            else if (bits[begin] == 0) {
                if (begin == bits.length - 1)
                    break;
                begin++;
            }
        }

        if (begin == bits.length)
            return false;
        return true;
    }
```

