# CEfficiencyTests
Testing optimizations in C

### Utilize Short Circuiting and Branch Prediction
```
//utilize short circuiting and branch prediction (slightly faster)
    if (h->y1 != horizontalYs[j])
      continue;
    if (h->x1 >= v->x1)
      continue;
    if (h->end <= v->x1)
      continue;
    if (v->y1 >= h->y1)
      continue;
    if (v->end <= h->y1)
      continue;
    thread_count++;
```

```
 //(slightly slower)
if ( h->x1 < v->x1 && h->end > v->x1 && v->y1 < h->y1 && v->end > h->y1) 
{
  thread_count++;
}

```
![image](https://github.com/user-attachments/assets/a09aeaf8-c4cb-4c4d-afe3-c48f644a5ef1)

![image](https://github.com/user-attachments/assets/50969ac7-20a0-4b1a-aaca-d4e87a859bac)
