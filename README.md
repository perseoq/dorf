# dorf (directory or file)

`dorf` es una utilidad de línea de comandos para verificar si una ruta en el sistema de archivos es un **directorio**, un **archivo**, o si **no existe**.  

## USO BÁSICO
```sh
dorf --path /ruta/app

Opciones:
  --path, -p     Ruta a verificar (obligatorio)
  --help, -h     Mostrar esta ayuda

```


## Compila
```
g++ dorf.cpp -o dorf -std=c++17
sudo mv dorf /usr/local/bin/
```

## Uso

```sh
dorf -p /etc/hosts
# ➜ Es un archivo.

dorf -p /etc/
# ➜ Es un directorio.

dof -p /ruta/inexistente
# ➜ La ruta no existe.
```

## Algunos ejemplos

```sh
# $HOME = /home/your_user

dorf --path $HOME/Projects/git_automatic/directory_or_file
Es un directorio.

dorf --path $HOME/Projects/git_automatic/directory_or_file/dorf.cpp 
Es un archivo.

dorf --path $HOME/Projects/git_automatic/directory_or_file/dorf.cpp.d 
La ruta no existe.
```


