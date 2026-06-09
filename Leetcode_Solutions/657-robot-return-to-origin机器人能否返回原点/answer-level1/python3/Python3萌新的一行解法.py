```
return (moves.count('R') == moves.count('L') and moves.count('U') == moves.count('D'))
```

通过count得出每个方向移动的次数，R和L对比 and U和D对比，直接return就阔以了