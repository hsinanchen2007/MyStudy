int count = 0;
for (int j = 0; j < J.length(); j++) {
    for (int s = 0; s < S.length(); s++)
        if (J.charAt(j) == S.charAt(s)) count++;
}
return count;