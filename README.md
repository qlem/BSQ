# BSQ

Program that find the biggest possible square on a map while avoiding obstacles. Developed in C.

## Screeshot

![alt text](https://raw.githubusercontent.com/qlem/BSQ/master/screenshot.png)

## Compile

```
./make
```

## Map generation

Make sure that the file "generation" is an executable.

Else :

```
chmod 755 generation
```

Example to generate a map :

```
./generation 30 20 3 > map_file
```

## Run

```
./bsq map_file
```