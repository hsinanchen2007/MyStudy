```
public boolean isOneBitCharacter(int[] bits) {
        for (int i = bits.length - 2; i >= 0; i--)if (bits[i] == 0) return (bits.length - i) % 2 == 0;
        return bits.length % 2 != 0;
    }
```
