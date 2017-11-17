# BSQ

Program that find the biggest possible square on a map while avoiding obstacles. Developed in C.

## Screeshot



## Compile

```
./make
```

## Map generation

Make sure that "generation" file is an executable.

Else :


```
chmod 755 generation

```

Example to generate a map :

```
./generation 20 20 3 > map_file
```

## Run

```
./bsq map_file
```