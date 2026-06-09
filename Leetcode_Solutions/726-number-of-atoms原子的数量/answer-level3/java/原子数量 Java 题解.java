去括号
TreeMap

```java
import java.util.TreeMap;

class Solution {

  public String countOfAtoms(String formula) {
    if (!formula.contains("(")) {
      TreeMap<String, Integer> map = new TreeMap<>();
      String atom = "";
      int len = 0;

      char[] chars = formula.toCharArray();
      atom = "" + chars[0];
      for (int i = 1; i < chars.length; i++) {
        if (Character.isUpperCase(chars[i])) {
          len = len == 0 ? 1 : len;
          if (map.containsKey(atom)) {
            map.put(atom, map.get(atom) + len);
          } else {
            map.put(atom, len);
          }
          len = 0;
          atom = "" + chars[i];

          continue;
        }
        if (Character.isLowerCase(chars[i])) {
          atom += chars[i];
          continue;
        }

        len = len * 10 + Character.getNumericValue(chars[i]);
      }

      len = len == 0 ? 1 : len;
      if (map.containsKey(atom)) {
        map.put(atom, map.get(atom) + len);
      } else {
        map.put(atom, len);
      }

      // calc
      StringBuilder sb = new StringBuilder();
      map.forEach((k, v) -> {
        sb.append(k);
        if (v > 1) {
          sb.append(v);
        }
      });
      return sb.toString();
    }

    if (formula.contains("(")) {
      int end = formula.indexOf(")");
      int begin = formula.lastIndexOf("(", end);

      int temp = 0;
      int cur = end + 1;
      while (cur < formula.length() && Character.isDigit(formula.charAt(cur))) {
        temp = temp * 10 + Character.getNumericValue(formula.charAt(cur));
        cur++;
      }

      if (temp == 0) {
        temp = 1;
      }
      String ff = flat(formula.substring(begin + 1, end), temp);

      formula = formula.substring(0, begin) + ff + formula.substring(cur);
    }
    return countOfAtoms(formula);
  }

  private String flat(String formula, int repeat) {
    char[] cs = formula.toCharArray();

    int temp = 0;
    StringBuilder sb = new StringBuilder();
    sb.append(cs[0]);
    for (int i = 1; i < cs.length; i++) {
      if (Character.isUpperCase(cs[i])) {
        if (temp == 0) {
          sb.append(repeat);
        } else {
          sb.append(temp * repeat);
        }
        temp = 0;
      }

      if (Character.isLetter(cs[i])) {
        sb.append(cs[i]);
        continue;
      }

      temp = temp * 10 + Character.getNumericValue(cs[i]);
    }

    if (temp == 0) {
      sb.append(repeat);
    } else {
      sb.append(repeat * temp);
    }

    return sb.toString();
  }
}


```