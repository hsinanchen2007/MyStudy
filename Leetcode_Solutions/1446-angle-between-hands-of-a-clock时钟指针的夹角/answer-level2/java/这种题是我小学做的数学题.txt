```
public double angleClock(int hour, int minutes) {
        double slow = 0.5d;
        double fast = 6d;
        
        double sd = (slow * (60 * hour + minutes)) % 360;
        double fd = (fast * (60 * hour + minutes)) % 360;
        
        double d = sd > fd ? sd - fd : fd - sd;
        if (d > 180) {
            d = 360 - d;
        }
        
        return d;
    }
```
